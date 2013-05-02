#ifndef PolyStatic_HeaderPlusPlus
#define PolyStatic_HeaderPlusPlus

#include <string>
#include <functional>
#include <memory>

namespace ps
{
	struct Value
	{
		//
	};
	struct Variable : Value
	{
		//Type
	};
	struct Type : Variable
	{
		//
	};
	struct Statement
	{
		//
	};
	struct Function : Variable
	{
		//Statements
	};
	struct Declaration
	{
	};
	struct Space : Declaration
	{
		//Declarations
	};
	struct Class : Type
	{
		//Space
	};

	struct Fluid
	{
		//Space
	};

	struct Error
	{
		Error(std::string const &emsg) noexcept
		: msg(emsg)
		{
		}
		Error(Error const &) noexcept = default;
		Error(Error &&) noexcept = default;
		Error &operator=(Error const &) noexcept = default;
		Error &operator=(Error &&) noexcept = default;
		~Error() noexcept = default;

		std::string const &message() const noexcept
		{
			return msg;
		}

	private:
		std::string msg;
	};
}

#endif
