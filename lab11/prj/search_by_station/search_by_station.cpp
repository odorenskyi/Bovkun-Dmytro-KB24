#include search_by_station.h
#include iostream
#include algorithm

void ScheduleSystemsearchByStation() const {
    stdstring name;
    stdcout  Введіть назву станції (початкову або кінцеву) ;
    stdgetline(stdcin, name);

    stdstring lowered;
    stdtransform(name.begin(), name.end(), stdback_inserter(lowered), tolower);

    bool found = false;
    for (const auto& r  routes) {
        stdstring route_lower = r.route;
        stdtransform(route_lower.begin(), route_lower.end(), route_lower.begin(), tolower);
        if (route_lower.find(lowered) != stdstringnpos) {
            stdcout  ID   r.id   —   r.route   (  r.frequency  ,   r.period  )n;
            found = true;
        }
    }
    if (!found) {
        stdcout  Рейсів за вказаною станцією не знайдено.n;
    }
}
