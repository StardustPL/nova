#ifndef PolyStatic_HeaderPlusPlus
#define PolyStatic_HeaderPlusPlus

#include <functional>
#include <memory>

namespace ps
{
	/**
	 * The Parser class is used collect various interrealted scripts
	 * and perform the task of syntactic parsing. Only syntactic errors
	 * can be discovered in this phase - all other intrepretation of
	 * scripts is handled by the Interpreter class.
	 *
	 * This class is not meant to be extended.
	 */
	struct Parser
	{
		Parser() noexcept;
		/**
		 * Construct a Parser from a script. The script name is considered
		 * to be "", or empty. Other scripts may still be added. The given
		 * character string is copied to an internal storage.
		 */
		Parser(char const *script);
		Parser(Parser const &parser);
		Parser(Parser &&parser) noexcept;
		~Parser() noexcept;

		/**
		 * Adds a script file reference to the script set. The file
		 * name is used as the name of the script. Only the given
		 * character string is copied to an internal storage; the
		 * file is not accessed until Parse() is called. If a script
		 * with the same name already exists, it will be overwritten.
		 */
		void AddScriptFile(char const *scriptfilename);
		/**
		 * Adds an in-memory script with the given name. If a script
		 * with the same name already exists, it will be overwritten.
		 * Both given character strings will be copied to an internal
		 * storage.
		 */
		void AddScript(char const *scriptname, char const *contents);
		/**
		 * Removes the script, by name, from the script set. This
		 * includes both script file references and in-memory scripts.
		 * Nothing happens if the script name doesn't exist.
		 */
		void RemoveScript(char const *scriptname);

		/**
		 * Represents an Error or warning caused by the syntax of
		 * a script.
		 */
		struct Error
		{
			/**
			 * The error or warning message, the format of which
			 * depends on the implementation. The returned character
			 * string is only valid while this Error is in scope.
			 */
			char const *ErrorString() const noexcept;
			/**
			 * The name of the script the error occurred in. This
			 * is the same as that set by either AddScriptFile() or
			 * AddScript(). The returned character string is only
			 * valid while this Error is in scope.
			 */
			char const *ScriptName() const noexcept;
			/**
			 * The first line the error occurs on.
			 */
			unsigned LineNumberStart() const noexcept;
			/**
			 * The last line the error cccurs on. Will be greator or
			 * equal to LineNumberStart().
			 */
			unsigned LineNumberEnd() const noexcept;
			/**
			 * The first character on the first line where the error
			 * occurs. All characters, including tabs, count for 1.
			 */
			unsigned ColumnNumberStart() const noexcept;
			/**
			 * The last character on the last line where the error
			 * occurs. All characters, including tabs, count for 1.
			 */
			unsigned ColumnNumberEnd() const noexcept;

		private:
			friend struct ::ps::Parser;

			Error() noexcept;
			Error(Error const &) noexcept;
			Error(Error &&) noexcept;
			Error &operator=(Error const &) noexcept;
			Error &operator=(Error &&) noexcept;
			~Error() noexcept;

			struct Impl;
			std::unique_ptr<Impl> impl;
		};

		/**
		 * The function signature for a function to handle parsing Errors.
		 * The parser that encountered the error is provided.
		 * A boolean is also provided indicatng whether the error
		 * is only a warning (true) or not (false). The function must return
		 * a boolean indicating whether parsing should continue (true) or
		 * not (false). This can simply mirror warning status.
		 */
		using ErrorHandler = std::function<bool (Parser &parser, Error const &error, bool warning) noexcept>;

		/**
		 * Sets or replaces the one and only ErrorHandler function for this
		 * parser. It is guaranteed to only be called during the execution
		 * of Parse().
		 */
		void SetErrorHandler(ErrorHandler const &eh) noexcept;

		/**
		 * Syntactically parses the script set, reporting errors and warnings
		 * via the ErrorHandler callback. The results of the parse are stored
		 * in memory to be used by an Interpreter. If called more than once,
		 * previous results are discarded and all input is parsed again.
		 */
		bool Parse() noexcept;

	private:
		Parser &operator=(Parser const &) = delete;
		Parser &operator=(Parser &&) = delete;

		struct Impl;
		std::unique_ptr<Impl> impl;

		friend struct ::ps::Interpreter;
		friend struct ::ps::Error;
	};

	/**
	 * An Interpreter will take the results of syntactic parsing from
	 * Parsers and convert it into the initial state of a program. This
	 * state can be preserved and copied, and can be modified via
	 * reflection or by invoking methods.
	 *
	 * This class is not meant to be extended.
	 */
	struct Interpreter
	{
		Interpreter() noexcept;
		Interpreter(Interpreter const &);
		Interpreter(Interpreter &&);
		Interpreter &operator=(Interpreter const &);
		Interpreter &operator=(Interpreter &&);
		~Interpreter();

		/**
		 * Represents an Error during evaluating a function.
		 */
		struct Error
		{
			/**
			 * The error or warning message, the format of which
			 * depends on the implementation. The returned character
			 * string is only valid while this Error is in scope.
			 */
			char const *ErrorString() const noexcept;

		private:
			friend struct ::ps::Interpreter;

			Error() noexcept;
			Error(Error const &) noexcept;
			Error(Error &&) noexcept;
			Error &operator=(Error const &) noexcept;
			Error &operator=(Error &&) noexcept;
			~Error() noexcept;

			struct Impl;
			std::unique_ptr<Impl> impl;
		};

		/**
		 * The function signature for a function to handle interpreting Errors.
		 * The interpreter that encountered the error is provided.
		 */
		using ErrorHandler = std::function<void (Parser &parser, Error const &error) noexcept>;

		/**
		 * Sets or replaces the one and only ErrorHandler function for this
		 * parser.
		 */
		void SetErrorHandler(ErrorHandler const &eh) noexcept;

		/**
		 * Adds the results of parsing a script set from a parser,
		 * uninitialized. When Initialize is called, they are merged
		 * into the current program state.
		 * If the parser has not yet parsed successfully, it is ignored.
		 */
		void Add(Parser const &parser);

		/**
		 * Initializes any uninitialized code, then merges
		 * with the current program state.
		 */
		void Initialize();

		//member functions to actually call initialized code

	private:
		struct Impl;
		std::unique_ptr<Impl> impl;
	};
	inline Interpreter::ErrorHandler::~ErrorHandler(){}
}

#endif
