#ifndef stardust_Dust_HeaderPlusPlus
#define stardust_Dust_HeaderPlusPlus

#include <string>
#include <cctype>
#include <vector>

namespace stardust
{
	struct Dust final
	{
		Dust() = default;
		Dust(Dust const &) = default;
		Dust &operator=(Dust const &) = default;
		Dust(Dust &&) = default;
		Dust &operator=(Dust &&) = default;
		~Dust() = default;

		struct Token final
		{
			Token(std::string const &token, std::size_t line, std::size_t column)
			: token(token)
			, line(line)
			, column(column)
			{
				for(auto const &c : token)
				{
					if(isspace(c))
					{
						throw std::invalid_argument{"token `"+token+'`'};
					}
				}
			}
			Token(Token const &) = default;
			Token &operator=(Token const &) = default;
			Token(Token &&) = default;
			Token &operator=(Token &&) = default;
			~Token() = default;

			//

		private:
			std::string token;
			std::size_t line;
			std::size_t column;
		};
		struct Line final
		{
			Line() = default;
			Line(Line const &) = default;
			Line &operator=(Line const &) = default;
			Line(Line &&) = default;
			Line &operator=(Line &&) = default;
			~Line() = default;

			template<typename... Args>
			Token &addToken(Args &&... args)
			{
				tokens.emplace_back(std::forward(args)...);
				return tokens.back();
			}
			template<typename... Args>
			Line &addLine(Args &&... args)
			{
				lines.emplace_back(std::forward(args)...);
				return lines.back();
			}

			//

		private:
			std::vector<Token> tokens;
			std::vector<Line> lines;
		};

		template<typename... Args>
		Line &addLine(Args &&... args)
		{
			lines.emplace_back(std::forward(args)...);
			return lines.back();
		}

		//

	private:
		std::vector<Line> lines;
	};
}

#endif
