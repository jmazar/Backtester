#ifndef _DATE_H
#define _DATE_H

#include <sstream>

class Date {
	public:
		Date() : m_year(0), m_month(0), m_day(0) {}
		Date(	unsigned int in_year,
				unsigned int in_month,
				unsigned int in_day) :
				m_year(in_year),
				m_month(in_month),
				m_day(in_day) {}

		Date( std::string const & in_date ) {
			std::stringstream date(in_date);
			std::string partofdate = "";
			getline(date, partofdate, '-');
			this->SetYear(atoi(partofdate.c_str()));
			getline(date, partofdate, '-');
			this->SetMonth(atoi(partofdate.c_str()));
			getline(date, partofdate, '-');
			this->SetDay(atoi(partofdate.c_str()));
		}

		inline bool operator<(Date const & in_date) const {
			if(this->GetYear() != in_date.GetYear()) {
				return this->GetYear() < in_date.GetYear();
			}
			else if(this->GetMonth() != in_date.GetMonth()) {
				return this->GetMonth() < in_date.GetMonth();
			}
			return this->GetDay() < in_date.GetDay();
		}

		inline bool operator==(Date const & in_date) const {
			return ((this->GetYear() == in_date.GetYear()) 
			&& (this->GetMonth() == in_date.GetMonth())
			&& (this->GetDay() == in_date.GetDay()));
		}

		unsigned int GetYear() const { return m_year; }
		unsigned int GetMonth() const { return m_month; }
		unsigned int GetDay() const { return m_day; }

		void SetYear(unsigned int const in_year) { m_year = in_year; }
		void SetMonth(unsigned int const in_month) { m_month = in_month; }
		void SetDay(unsigned int const in_day) { m_day = in_day; }
	private:
		unsigned int m_year;
		unsigned int m_month;
		unsigned int m_day;
};
#endif
