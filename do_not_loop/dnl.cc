#include "dnl.hh"

size_t min_elt_length(const std::vector<std::string>& req)
{
    return std::min_element(req.begin(), req.end())->size();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    return std::max_element(req.begin(), req.end())->size();
}

size_t sum_elt_length(const std::vector<std::string>& req)
{
    return std::accumulate(
        req.begin(), req.end(), 0,
        [](size_t sum, const std::string& elt) { return sum + elt.length(); });
}

size_t count_elt(const std::vector<std::string>& req, const std::string& elt)
{
    return std::count(req.begin(), req.end(), elt);
}

size_t count_duplicate(const std::vector<std::string>& req)
{
    std::vector<std::string> vec;
    copy(req.begin(), req.end(), back_inserter(vec));
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    return vec.size();
}