#include <gtest/gtest.h>

#include <html/html.h>
#include <html/head.h>
#include <html/head/title.h>
#include <html/head/meta.h>
#include <html/body.h>

#include <html/link.h>

#include <html/attribute.h>

#include <html/code.h>
#include <html/comment.h>
#include <html/div.h>
#include <html/span.h>
#include <html/fmt/hex.h>

#include "etalon_path.h"
#include <fstream>


TEST(html, CompareWithEtalon)
{
	constexpr const char *filePath = EtalonHtmlPath;


	html::Html html;

	{
		html::Head head;

		head << (html::head::Title() << "Title");

		head << html::head::Meta(L"author",		L"SD");
		head << html::head::Meta(L"charset",	L"utf-8");
		head << html::head::Meta(L"generator",	L"Test html");

		html << head;
	}

	{
		html::Body body;
		body << "Line 1.1" << ":" << "Line 1.2\n";
		body << "Line 2.1" << ":" << "Line 2.2\n";

		body << "    spaces test\n";

		body << "\n\n";

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

			body << html::Span() % html::style::Color(L"red") << "Red text" << "+red text\n" >> html::Revert<html::Span>() << "This is default color text\n";

			auto cyanColor = []() -> html::Span { return html::Span() % html::style::Color(L"cyan"); };
			body << cyanColor() << "This is cyan color text\n";
			body << "And this too\n" >> html::Revert<decltype(cyanColor())>();
			body << "This is default color text\n";

			body << "\n";

			{ // double color
				body <<
						cyanColor() << "This is cyan color\n" <<
							html::Span() % html::style::Color(L"magenta") << "another color " >> html::Revert<html::Span>() <<
						"Cyan" >> html::Revert<html::Span>() <<
					"default color\n";

			}
		}

		body << "\n\n";

		body << (html::Comment() << "this is " << "comment\n" << "This is line two of comment");

		html::Attribute titleAttr(L"title=\"This is title of div\"");

		{
			html::Div div;
			div << "This is div block\n";

			div << html::Div() % titleAttr % html::Attribute(L"align=right") << "TEXT IN DIV WITH ATTR\n" >> html::Revert<html::Div>();

			body << div;
			body << L"and again: ";
			body << div;
		}

		body % html::Style(L"background-color", L"lightblue");

		{
			body << html::Link(L"https://www.w3schools.com") << L"W3S School" >> html::Revert<html::Link>() << "\n";
			body << html::Link(L"https://www.w3schools.com") % html::style::Color(L"red") << L"W3S School" >> html::Revert<html::Link>() << "\n";
			body << html::Link(L"#anchor-1") % html::style::Color(L"red") << L"Click me" >> html::Revert<html::Link>() << "\n";
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
			body	<< html::Div()
						% html::attribute::Id(L"anchor-1")
						% html::Style(L"font-family", L"verdana")
						% html::Style(L"font-size", L"20px")
						% titleAttr
						% html::style::Color(L"red")
					<< "Custom div" >> html::Revert<html::Div>();
		}

		body << html::fmt::Hex() % 0x123abc << " - hex value\n";
		body << 0x123abc << " - not hex value\n";

		html << body;
	}


	// write to file
	if (0)
	{
		std::wfstream fileStream;
		fileStream.open(filePath, std::fstream::out);
		ASSERT_TRUE(fileStream.is_open());

		fileStream << html;
	}
	else
	{
		std::wstringstream dynamicHtml;
		dynamicHtml << html;
		dynamicHtml.seekp(0);

		std::wfstream etalonHtml;
		etalonHtml.open(filePath, std::fstream::in);
		ASSERT_TRUE(etalonHtml.is_open());

		std::wstring generated;
		std::wstring etalon;
		while (etalonHtml.good() && dynamicHtml.good())
		{
			etalonHtml	>> etalon;
			dynamicHtml >> generated;

			EXPECT_EQ(etalon, generated);
		}

		EXPECT_TRUE(etalonHtml.eof() == dynamicHtml.eof());
	}
}
