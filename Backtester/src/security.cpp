#include "security.h"

Security::Security() {
}

Security::~Security() {
}


void Security::AddInfo(SecurityInfo const & in_info) {
    m_info.push_back(in_info);
}

std::vector<Security::SecurityInfo> Security::GetInfo(unsigned int in_beginDate, unsigned int in_endDate) {
    std::vector<SecurityInfo> outInfo;

    for(auto iterator = m_info.begin(); iterator != m_info.end(); iterator++) {
        if(iterator->date >= in_beginDate && iterator->date <= in_endDate) {
            outInfo.push_back(*iterator);
        }
    }

    return outInfo;
}
