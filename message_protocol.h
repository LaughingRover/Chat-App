#pragma once
#include <string>
#include <unordered_map>
#include <sstream>

class MessageType
{
public:
	static constexpr const char *LOGIN = "LOGIN";
	static constexpr const char *MESSAGE = "MESSAGE";
	static constexpr const char *LOGOUT = "LOGOUT";
	static constexpr const char *CONNECT = "CONNECT";
	static constexpr const char *DISCONNECT = "DISCONNECT";
	static constexpr const char *SESSION_START = "SESSION_START";
	static constexpr const char *SESSION_END = "SESSION_END";
	static constexpr const char *HEARTBEAT = "HEARTBEAT";
	static constexpr const char *ERROR = "ERROR";
};

class Protocol
{
public:
	static std::string encodeLogin(const std::string &username,
								   const std::string &password)
	{
		return "MessageType:" + std::string(MessageType::LOGIN) +
			   ";Username:" + username + ";Password:" + password;
	}

	static std::string encodeMessage(const std::string &fromUser,
									 const std::string &toUser,
									 const std::string &content)
	{
		return "MessageType:" + std::string(MessageType::MESSAGE) +
			   ";From:" + fromUser + ";To:" + toUser + ";Content:" + content;
	}

	static std::string encodeLogout(const std::string &username)
	{
		return "MessageType:" + std::string(MessageType::LOGOUT) +
			   ";Username:" + username;
	}

	static std::string encodeConnect(const std::string &clientId,
									 const std::string &timestamp)
	{
		return "MessageType:" + std::string(MessageType::CONNECT) +
			   ";ClientID:" + clientId + ";Timestamp:" + timestamp;
	}

	static std::string encodeDisconnect(const std::string &clientId,
										const std::string &timestamp)
	{
		return "MessageType:" + std::string(MessageType::DISCONNECT) +
			   ";ClientID:" + clientId + ";Timestamp:" + timestamp;
	}

	static std::string encodeSessionStart(const std::string &sessionId,
										  const std::string &userId,
										  const std::string &timestamp)
	{
		return "MessageType:" + std::string(MessageType::SESSION_START) +
			   ";SessionID:" + sessionId + ";UserID:" + userId + ";Timestamp:" +
			   timestamp;
	}

	static std::string encodeSessionEnd(const std::string &sessionId,
										const std::string &timestamp)
	{
		return "MessageType:" + std::string(MessageType::SESSION_END) +
			   ";SessionID:" + sessionId + ";Timestamp:" + timestamp;
	}

	static std::string encodeHeartbeat(const std::string &sessionId,
									   const std::string &timestamp)
	{
		return "MessageType:" + std::string(MessageType::HEARTBEAT) +
			   ";SessionID:" + sessionId + ";Timestamp:" + timestamp;
	}

	static std::string encodeError(int errorCode,
								   const std::string &description)
	{
		return "MessageType:" + std::string(MessageType::ERROR) +
			   ";Code:" + std::to_string(errorCode) + ";Description:" +
			   description;
	}

	static std::unordered_map<std::string, std::string> decodeMessage(
		const std::string &message)
	{
		std::unordered_map<std::string, std::string> messageDict;
		std::istringstream ss(message);
		std::string part;

		while (std::getline(ss, part, ';'))
		{
			auto delimeterPos = part.find(':');
			if (delimeterPos != std::string::npos)
			{
				std::string key = part.substr(0, delimeterPos);
				std::string value = part.substr(delimeterPos + 1);
				messageDict[key] = value;
			}
		}
		return messageDict;
	}
};
