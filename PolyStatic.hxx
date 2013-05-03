#ifndef PolyStatic_HeaderPlusPlus
#define PolyStatic_HeaderPlusPlus

#include <string>
#include <functional>
#include <memory>
#include <type_traits>

namespace ps
{
	template<typename PSType>
	struct Value
	{
		//
		virtual ~Value() noexcept = default;
	};
	template<typename PSType>
	struct Variable : Value<PSType>
	{
		//
	};
	namespace types
	{
		template<typename Derived = void>
		struct Type : Type<void>
		{
			using DerivedType = std::enable_if<std::is_base_of<Type, Derived>::value>::type;
		};
		template<>
		struct Type<void> : Variable<Type<void>>
		{
		};
		struct Void : Type<Void>
		{
			//
		};
		struct Int : Type<Int>
		{
			//
		};
		struct Float : Type<Float>
		{
			//
		};
		struct Function : Type<Function>
		{
			//
		};
		struct Class : Type<Class>
		{
			//
		};
		struct String : Class
		{
			//
		};
	}
	struct Statement
	{
		//
	};
	struct Declaration
	{
	};
	struct Space : Declaration
	{
		//Declarations
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
