/*
 * NS.h
 *
 *  Created on: 26-Mar-2015
 *      Author: Vamsi and Manoj
 */

#ifndef NS_H_
#define NS_H_
#include <string>
#include <cstring>
#include <malloc.h>
#include <fstream>
#include <sstream>
#include "Graph.h"

namespace std {
/*
* Namespace class 
*/
class NS {
	map<string,Graph> names;
	vector<string> commands;
public:
	NS();
	bool isPresent(string s);
	void run();
	virtual ~NS();
};

} /* namespace std */

#endif /* NS_H_ */
