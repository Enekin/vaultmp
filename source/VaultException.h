#ifndef VAULTEXCEPTION_H
#define VAULTEXCEPTION_H

#ifdef __WIN32__
#include <winsock2.h>
#endif

#include <cstdio>
#include <string>
#include <typeinfo>

#include "vaultmp.h"

#ifdef VAULTMP_DEBUG
#include "Debug.h"
#include "dbg/stack.hpp"
#include <ostream>
#endif

/**
 * \brief The exception class of vaultmp
 *
 * Stores an exception message and is able to print it to either a MessageBox or to the console
 */

class VaultException : public std::exception
{
	private:
		std::string error;

#ifdef VAULTMP_DEBUG
		static DebugInput<VaultException> debug;
		static void stacktrace();
#endif

		VaultException& operator=(const VaultException&) = delete;

	public:
		VaultException(const std::string& error);
		VaultException(const char* format, ...);
		virtual ~VaultException() throw() {}

		/**
		 * \brief Creates a MessageBox displaying the exception message (Win32 only)
		 */
		void Message();
		/**
		 * \brief Prints the exception message to the console
		 */
		void Console();

		virtual const char* what() const throw();
};

#endif
