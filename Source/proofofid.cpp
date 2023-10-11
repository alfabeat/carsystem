#include <utility>
#include <sstream>
#include <string>
#include "proofofid.h"

std::string proofofid::getproof(void) {
	return proofid;
}
void proofofid::setfproof(std::string aproof) {
	proofid = aproof;
}
proofofid::proofofid(std::string aproof)
	: proofid(aproof) {

}