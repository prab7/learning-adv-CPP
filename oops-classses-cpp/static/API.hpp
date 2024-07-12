#ifndef API_HPP
#define API_HPP

struct API{
    API();
    ~API();

    // Member variable that belonds to each instance
    int m_local;
    static int MAJOR;
    static int MINOR;

    static int GetMajorVerStat();
};

#endif