/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/**
 * @file      Group.cpp
 * @since     Jun 22, 2018
 * @author    Patricio A. Rossi (MeduZa)
 * @copyright Copyright © 2018 Patricio A. Rossi (MeduZa)
 */

#include "Group.hpp"

using namespace LEDSpicer::Devices;

void Group::drawElements() {
	cout << (int)elements.size() << " Element(s): " << endl;
	for (auto element : elements) {
		cout << std::left << std::setfill(' ') << std::setw(15) << element->getName() <<
			" Pin" << (element->getPins().size() == 1 ? " " : "s") <<  ": ";
		for (auto pin : element->getPins()) {
			cout << std::setw(2) << (int)*pin << " ";
		}
		cout << endl;
	}
}

uint8_t Group::size() const {
	return elements.size();
}

void Group::linkElement(Element* element) {
	elements.push_back(element);
}

void Group::shrinkToFit() {
	elements.shrink_to_fit();
}

const vector<Element*>& Group::getElements() const {
	return elements;
}

Element* Group::getElement(uint8_t index) {
	return elements.at(index);
}

const string& Group::getName() const {
	return name;
}
