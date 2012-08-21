#ifndef _SECURITY_H
#define _SECURITY_H

#include <vector>
#include <string>

class Security {
    public:
        Security();
        virtual ~Security();
        typedef struct {
            unsigned int    date;
            double          open;
            double          close;
            double          high;
            double          low;
            unsigned int    volume;
        } SecurityInfo;
        void AddInfo(SecurityInfo const & in_info);
        std::vector<SecurityInfo> GetInfo(unsigned int in_beginDate, unsigned int in_endDate) const;
    private:
        std::string m_name;
        std::vector<SecurityInfo> m_info;
};

#endif
