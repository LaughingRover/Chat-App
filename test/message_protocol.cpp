#include <iostream>
#include "../message_protocol.h"
#include <stdio.h>

int main()
{
	std::string loginMessage = Protocol::encodeLogin("User123", "Password123");
	std::cout << "Encoded Login Message: " << loginMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedLoginMessage = Protocol::decodeMessage(loginMessage);
	std::cout << "Decoded Login Message: ";
	for (const auto &pair : decodedLoginMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string textMessage = Protocol::encodeMessage("User123", "User456", "Hello, World!");
	std::cout << "Encoded Text Message: " << textMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedTextMessage = Protocol::decodeMessage(textMessage);
	std::cout << "Decoded Text Message: ";
	for (const auto &pair : decodedTextMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string logoutMessage = Protocol::encodeLogout("User123");
	std::cout << "Encoded Logout Message: " << logoutMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedLogoutMessage = Protocol::decodeMessage(logoutMessage);
	std::cout << "Decoded Logout Message: ";
	for (const auto &pair : decodedLogoutMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string connectMessage = Protocol::encodeConnect("Client123", "1623847382");
	std::cout << "Encoded Connect Message: " << connectMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedConnectMessage = Protocol::decodeMessage(connectMessage);
	std::cout << "Decoded Connect Message: ";
	for (const auto &pair : decodedConnectMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string sessionStartMessage = Protocol::encodeSessionStart("Session123", "User123", "1623847382");
	std::cout << "Encoded Session Start Message: " << sessionStartMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedSessionStartMessage = Protocol::decodeMessage(sessionStartMessage);
	std::cout << "Decoded Session Start Message: ";
	for (const auto &pair : decodedSessionStartMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string heartbeatMessage = Protocol::encodeHeartbeat("Session123", "1623847382");
	std::cout << "Encoded Heartbeat Message: " << heartbeatMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedHeartbeatMessage = Protocol::decodeMessage(heartbeatMessage);
	std::cout << "Decoded Heartbeat Message: ";
	for (const auto &pair : decodedHeartbeatMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string sessionEndMessage = Protocol::encodeSessionEnd("Session123", "1623847382");
	std::cout << "Encoded Session End Message: " << sessionEndMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedSessionEndMessage = Protocol::decodeMessage(sessionEndMessage);
	std::cout << "Decoded Session End Message: ";
	for (const auto &pair : decodedSessionEndMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	std::string errorMessage = Protocol::encodeError(100, "InvalidCredentials");
	std::cout << "Encoded Error Message: " << errorMessage << std::endl;

	std::unordered_map<std::string, std::string> decodedErrorMessage = Protocol::decodeMessage(errorMessage);
	std::cout << "Decoded Error Message: ";
	for (const auto &pair : decodedErrorMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	errorMessage = Protocol::encodeError(101, "UserNotFound");
	std::cout << "Encoded Error Message: " << errorMessage << std::endl;

	decodedErrorMessage = Protocol::decodeMessage(errorMessage);
	std::cout << "Decoded Error Message: ";
	for (const auto &pair : decodedErrorMessage)
	{
		std::cout << pair.first << ": " << pair.second << "; ";
	}
	std::cout << std::endl;

	return 0;
}
