/*
 * App.hpp
 *
 *  Created on: 1-mei-2012
 *      Author: stefan
 */

#ifndef APP_HPP_
#define APP_HPP_


namespace capselchi {

class App {
public:
	int run(void);

protected:
	void init(void);
	void loop(void);
	void cleanup(void);

private:
};

}  // namespace capselchi

#endif /* APP_HPP_ */
