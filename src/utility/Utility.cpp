/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**
 * @file      Utility.cpp
 * @since     Jun 24, 2018
 * @author    Patricio A. Rossi (MeduZa)
 * @copyright Copyright © 2018 - 2019 Patricio A. Rossi (MeduZa)
 */

#include "Utility.hpp"

using namespace LEDSpicer;

int Utility::parseNumber(const string& number, const string& errorMessage) {
	try {
		return std::stoi(number);
	} catch (...) {
		throw Error(errorMessage);
	}
}

void Utility::ltrim(string& text) {
	size_t chars = 0;
	for (size_t c = 0; c < text.size(); c++) {
		if (text[c] != ' ' and text[c] != '\n' and text[c] != '\t')
			break;
		chars ++;
	}
	if (chars)
		text.erase(0, chars);
}

void Utility::rtrim(string& text) {
	size_t chars = 0;
	for (size_t c = text.size(); c > 0; c--) {
		if (text[c] != ' ' and c != '\n' and c != '\t')
			break;
		chars ++;
	}
	if (chars)
		text.resize(text.size() - chars + 1);
}

void Utility::trim(string& text) {
	ltrim(text);
	rtrim(text);
}

void Utility::checkAttributes(
	const vector<string>& attributeList,
	const umap<string, string>& subjects,
	const string& place)
{
	for (string attribute : attributeList)
		if (not subjects.count(attribute))
			throw Error("Missing attribute '" + attribute + "' inside " + place);
}

vector<string> Utility::explode(const string& text, const char delimiter, const size_t limit) {

	vector<string> temp;

	size_t start = 0, end = 0;

	for (size_t c = 0; limit ? c < limit : true; c++) {
		end = text.find(delimiter, start);
		if (end == string::npos) {
			temp.push_back(text.substr(start));
			break;
		}
		temp.push_back(text.substr(start, end - start));
		start = end + 1;
	}

	return std::move(temp);
}

string Utility::hex2str(int number) {
	std::stringstream stream;
	stream << std::hex << std::showbase << number;
	return string(stream.str());
}

string Utility::removeChar(const string& str, char c) {
	string result;
	for (char currentChar : str)
		if (currentChar != c)
			result += currentChar;
	return result;
}
