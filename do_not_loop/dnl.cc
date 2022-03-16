#include "dnl.hh"

size_t min_elt_length(const std::vector<std::string>& req)
{
    return std::min_element(req.begin(), req.end(),
                            [](auto a, auto b) { return a.size() < b.size(); })
        ->size();
}

size_t max_elt_length(const std::vector<std::string>& req)
{
    return std::max_element(req.begin(), req.end(),
                            [](auto a, auto b) { return a.size() < b.size(); })
        ->size();
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
    std::unordered_map<std::string, int> tmp;
    std::transform(req.begin(), req.end(), std::inserter(tmp, tmp.end()),
                   [](const auto& c) { return std::make_pair(c, 0); });
    return req.size() - tmp.size();
}