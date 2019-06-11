//Charles Dodge
//CIST 2362 CRN 63228
//Midterm Project

#ifndef MIDTERM_PROJECT_DATETYPE_H
#define MIDTERM_PROJECT_DATETYPE_H


class dateType {
private:
    int dMonth;
    int dDay;
    int dYear;

    bool isLeapYear(int) const;

    void checkDates(int, int, int);

public:
    //Constructor
    dateType(int = 1, int = 1, int = 1990);

    //Setters
    void setDate(int, int, int);
    void setMonth(int dMonth);
    void setDay(int dDay);
    void setYear(int dYear);

    //Getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    //Misc
    void printDate() const;
    bool isLeapYear() const;
    int daysInMonth() const;
    int daysPassed() const;
    int daysRemaining() const;

    void addDays(int);


    //
    //RelationalOperators
    //
    bool operator<(const dateType &rhs) const;

    bool operator>(const dateType &rhs) const;

    bool operator<=(const dateType &rhs) const;

    bool operator>=(const dateType &rhs) const;


    class IllegalDate : std::exception {
    private:
        int day;
        int month;
        std::string msg;
    public:
        IllegalDate(int day, int month) : day(day), month(month) {
            msg = "day " + std::to_string(day) + " in month " + std::to_string(month) + " is illegal";
        }

        std::string getMsg() {
            return msg;
        }
    };
};

const static int daysInMonths[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
#endif //MIDTERM_PROJECT_DATETYPE_H
