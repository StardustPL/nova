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
		template<typename = void> struct Type;
		template<>
		struct Type<void> : Variable<Type<void>>
		{
		};
		template<typename Derived>
		struct Type : Type<void>
		{
			static_assert(std::is_base_of<Type, Derived>::value, "Template parameter must be the deriving class");
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
		virtual ~Statement() noexcept = default;
	};
	struct Declaration
	{
		virtual ~Declaration() noexcept = default;
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
