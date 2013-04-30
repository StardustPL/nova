#include "PolyStatic.hpp"

#include <string>
#include <map>
#include <fstream>

namespace ps
{
	namespace
	{
		struct ParseElement
		{
			virtual ParseElement *Clone() const = 0;
			virtual ~ParseElement(){}
		};
		struct ScriptFile : public virtual ParseElement
		{
			std::string filename;
			ScriptFile(std::string const&filename) : filename(filename) {}
			virtual ScriptFile *Clone() const
			{
				return new ScriptFile(*this);
			}
			virtual ~ScriptFile(){}
		};
		struct Script : public virtual ParseElement
		{
			std::string script;
			Script(std::string const&script) : script(script) {}
			virtual Script *Clone() const
			{
				return new Script(*this);
			}
			virtual ~Script(){}
		};
		bool DEH(Parser &, Parser::Error const&, bool w){return w;}
	}
	struct Parser::Impl
	{
		typedef std::map<std::string, ParseElement *> elems_t;
		elems_t elems;
		ErrorHandler *eh;

		Impl() : eh(&DEH)
		{
		}
		Impl(Impl const&impl) : eh(&DEH)
		{
			for(elems_t::const_iterator it = impl.elems.begin(); it != impl.elems.end(); ++it)
			{
				elems[it->first] = it->second->Clone();
			}
		}
		~Impl()
		{
			for(elems_t::iterator it = elems.begin(); it != elems.end(); ++it)
			{
				delete it->second;
			}
		}
	};
	Parser::Parser() : impl(new Impl)
	{
	}
	Parser::Parser(char const*script) : impl(new Impl)
	{
		impl->elems[""] = new Script(script);
	}
	Parser::Parser(Parser const&parser) : impl(new Impl(*parser.impl))
	{
	}
	Parser::~Parser()
	{
		delete impl;
		impl = 0;
	}

	void Parser::AddScriptFile(char const*scriptfilename)
	{
		RemoveScript(scriptfilename);
		impl->elems[scriptfilename] = new ScriptFile(scriptfilename);
	}
	void Parser::AddScript(char const*scriptname, char const*contents)
	{
		RemoveScript(scriptname);
		impl->elems[scriptname] = new Script(contents);
	}
	void Parser::RemoveScript(char const*scriptname)
	{
		Impl::elems_t e (impl->elems);
		if(e.find(scriptname) != e.end())
		{
			delete e[scriptname];
			e.erase(scriptname);
		}
	}

	void Parser::SetErrorHandler(ErrorHandler &eh)
	{
		impl->eh = &eh;
	}
	struct Parser::Error::Impl
	{
		std::string msg, script;
		unsigned lns, lne, cns, cne;
	};
	Parser::Error::Error() : impl(new Impl)
	{
	}
	Parser::Error::~Error()
	{
		delete impl;
		impl = 0;
	}
	char const*Parser::Error::ErrorString() const
	{
		return impl->msg.c_str();
	}
	char const*Parser::Error::ScriptName() const
	{
		return impl->script.c_str();
	}
	unsigned Parser::Error::LineNumberStart() const
	{
		return impl->lns;
	}
	unsigned Parser::Error::LineNumberEnd() const
	{
		return impl->lne;
	}
	unsigned Parser::Error::ColumnNumberStart() const
	{
		return impl->cns;
	}
	unsigned Parser::Error::ColumnNumberEnd() const
	{
		return impl->cne;
	}

	bool Parser::Parse()
	{
		return false;
	}
}
