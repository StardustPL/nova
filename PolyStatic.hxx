#ifndef PolyStatic_HeaderPlusPlus
#define PolyStatic_HeaderPlusPlus

#include <string>
#include <functional>
#include <memory>
#include <type_traits>
#include <ostream>

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
		bool merge(std::string const &file, std::ostream &errors = std::err)
		{
			//
		}
	};
}

#endif
