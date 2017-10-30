#include <gtest/gtest.h>

#include <html/html.h>
#include <html/head.h>
#include <html/head/title.h>
#include <html/head/meta.h>
#include <html/head/css.h>
#include <html/body.h>

#include <html/link.h>

#include <html/attribute.h>

#include <html/code.h>
#include <html/comment.h>
#include <html/div.h>
#include <html/span.h>

#include <html/progress.h>

#include <html/fmt/hex.h>

#include <html/push_pop.h>

#include "etalon_path.h"
#include <fstream>


static std::wstring Stream2Str(std::wistream &stream)
{
	std::wstring data;

	std::wstring buffer;
	while (stream.good())
	{
		stream >> buffer;
		data += buffer;
	}

	return data;
}

static std::wstring ClearFromNonFunctionalSymbols(std::wstring data)
{
	const auto it = std::remove_if(std::begin(data), std::end(data), [](const auto ch)
	{
		switch (ch)
		{
		case L'\n':
		case L'\t':
		case L' ':
			return true;

		default:
			return false;
		}
	});

	data.erase(it, std::end(data));

	return data;
}


//////////////////////////////////////////////////////////////////////////
TEST(html, CompareWithEtalon)
{
	const auto filePath = std::string(EtalonHtmlPath) + "/etalon.html";


	html::Html html;

	{
		html::Head head;

		head << (html::head::Title() << "Title");

		head << html::head::Meta(L"keywords",	L"html generator");
		head << html::head::meta::Author(L"SD");
		head << html::head::meta::Charset(L"utf-8");
		head << html::head::meta::Generator(L"Test html");

		{ // CSS
			html::head::Css css;

			const auto cssFilePath = std::string(EtalonHtmlPath) + "/css.css";

			std::wfstream cssFile;
			cssFile.open(cssFilePath.c_str(), std::fstream::in);
			css << cssFile.rdbuf();

			head << css;
		}

		html << head;
	}

	{
		html::Body body;
		body << "Line 1.1" << ":" << "Line 1.2\n";
		body << "Line 2.1" << ":" << "Line 2.2\n";

		body << "    spaces test\n";

		body << "\n\n";

		// progress
		for (uint32_t val = 0; val <= 10; val++)
			body << html::Progress(10, val) << html::Progress(10, 10-val) << "\n";

		// Color test
		{
			const auto blueDiv = (html::Div() % html::style::Color(L"blue"));
			{
				auto d1 = blueDiv;
				d1 << "Div 1 with blue color text\n";
				auto d2 = blueDiv;
				d2 << "Div 2 with blue color text\n";

				body << d1 << d2;

				d2 % html::Attribute(L"draggable", true) << "+Draggable\n";
				body << d2;
			}

			body << html::Push<html::Span>() % html::style::Color(L"red") << "Red text" << "+red text\n" >> html::Pop<html::Span>() << "This is default color text\n";

			const auto cyanColor = []() -> html::Span { return html::Span() % html::style::Color(L"cyan"); };
			body << html::Push(cyanColor()) << "This is cyan color text\n" << "And this too\n" >> html::Pop(cyanColor());
			body << "This is default color text\n";

			body << "\n";

			{ // double color
				body <<
						(cyanColor() << "This is cyan color\n" <<
							html::Push<html::Span>() % html::style::Color(L"magenta") << "another color " >> html::Pop<html::Span>() <<
						"Cyan") <<
					"default color\n";

			}
		}

		body << "\n\n";

		body << (html::Comment() << "this is " << "comment\n" << "This is line two of comment");

		const html::attribute::Title titleAttr(L"This is title of div");

		{
			html::Div div;
			div << "This is div block\n";

			div << html::Push<html::Div>() % titleAttr % html::Attribute(L"align=right") << "TEXT IN DIV WITH ATTR\n" >> html::Pop<html::Div>();

			body << div;
			body << L"and again: ";
			body << div;
		}

		body % html::Style(L"background-color", L"lightblue");

		{
			body << html::Push<html::Link>(L"https://www.w3schools.com") << L"W3S School" >> html::Pop<html::Link>() << "\n";
			body << html::Push<html::Link>(L"https://www.w3schools.com") % html::style::Color(L"red") << L"W3S School" >> html::Pop<html::Link>() << "\n";
			body << html::Push<html::Link>(L"#anchor-1") % html::style::Color(L"red") << L"Click me" >> html::Pop<html::Link>() << "\n";
		}

		{ // code block
			html::Code code;
			code <<
				L"html::Div div;\n"
				L"div << \"This is div block\\n\";\n"
				L"body << div;\n"
				L"body << L\"and again: \";\n"
				L"body << div;\n";
			code % html::attribute::Title(L"Code block");
			code % html::Attribute(L"draggable", true) << L"Text after set attribute";
			code << "\n";

			body << code;
		}

		body << "Text after div block";

		{
			body << html::Push<html::Div>()
						% html::attribute::Id(L"anchor-1")
						% html::Style(L"font-family", L"verdana")
						% html::Style(L"font-size", L"20px")
						% titleAttr
						% html::style::Color(L"red")
					<< "Custom div" >> html::Pop<html::Div>();
		}

		body << html::fmt::Hex() % 0x123abc << " - hex value\n";
		body << 0x123abc << " - not hex value\n";

		html << body;
	}


	// write to file
	if (0)
	{
		std::wfstream fileStream;
		fileStream.open(filePath.c_str(), std::fstream::out);
		ASSERT_TRUE(fileStream.is_open());

		fileStream << html;
	}
	else
	{
		std::wstringstream dynamicHtml;
		dynamicHtml << html;
		dynamicHtml.seekp(0);

		std::wfstream etalonHtml;
		etalonHtml.open(filePath.c_str(), std::fstream::in);
		ASSERT_TRUE(etalonHtml.is_open());

		const std::wstring generated	= ClearFromNonFunctionalSymbols(Stream2Str(dynamicHtml));
		const std::wstring etalon		= ClearFromNonFunctionalSymbols(Stream2Str(etalonHtml));

		EXPECT_EQ(etalon, generated);

		EXPECT_TRUE(etalonHtml.eof() == dynamicHtml.eof());
	}
}
