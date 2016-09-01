# VKAuthenticator

VKAuthenticator is a simple QT class that performs authentication and obtains OAuth token from [VK.COM API](https://vk.com/dev/access_token).

It uses QT **core**, **gui**, **network** and **widgets**.
To request username/password dialog is shown. Important warnings are printed in QMessageBox.

Because no **WebKit** nor **WebEngine** are needed to perform authorization flow it can be statically built which sometimes is very important for standalone applications.

The interface of VKAuthenticator is described in header file.
In a nutshell, 
 - user need to provide application id and permissions list to the constructor
 - authentication should be triggered by public slot _authenticate_
 - user can subscribe for signals _error_ or _tokenReceived_ to check the status of authentication
 - or get error message or token by calling corresponding getter
 
 
The code is ugly and barely readable because I didn't have time to write it properly, so I apologize.

Any comments and questions are welcome.
