#include "dico.hh"

Dico::Dico(const std::set<std::string>& dico)
{
    dico_ = dico;
}

void Dico::dump_dico() const
{
    for (auto word : dico_)
    {
        std::cout << word << "\n";
    }
}

bool Dico::add_word(const std::string& s)
{
    if (dico_.find(s) != dico_.end())
        return false;
    dico_.insert(s);
    return true;
}

bool Dico::remove_word(const std::string& s)
{
    if (dico_.find(s) == dico_.end())
        return false;
    dico_.erase(s);
    return true;
}

std::set<std::string> Dico::find_prefix(const std::string& req) const
{
    std::set<std::string> prefix_list;
    for (auto word : dico_)
    {
        if (word.find(req) == 0)
            prefix_list.insert(word);
    }
    return prefix_list;
}

std::set<std::string> Dico::find_suffix(const std::string& req) const
{
    std::set<std::string> prefix_list;
    for (auto word : dico_)
    {
        if (req.size() < word.size()
            && std::equal(req.rbegin(), req.rend(), word.rbegin()))
            prefix_list.insert(word);
    }
    return prefix_list;
}

std::set<std::string> Dico::contains(const std::string& req) const
{
    std::set<std::string> prefix_list;
    for (auto word : dico_)
    {
        if (word.find(req) != std::string::npos)
            prefix_list.insert(word);
    }
    return prefix_list;
}

int min(int x, int y, int z)
{
    return std::min(std::min(x, y), z);
}

unsigned levenshtein_aux(const std::string& str1, const std::string& str2, int m, int n)
{
    // If first string is empty, the only option is to
    // insert all characters of second string into first
    if (m == 0)
        return n;

    // If second string is empty, the only option is to
    // remove all characters of first string
    if (n == 0)
        return m;

    // If last characters of two strings are same, nothing
    // much to do. Ignore last characters and get count for
    // remaining strings.
    if (str1[m - 1] == str2[n - 1])
        return levenshtein_aux(str1, str2, m - 1, n - 1);

    // If last characters are not same, consider all three
    // operations on last character of first string,
    // recursively compute minimum cost for all three
    // operations and take minimum of three values.
    return 1
        + min(levenshtein_aux(str1, str2, m, n - 1), // Insert
              levenshtein_aux(str1, str2, m - 1, n), // Remove
              levenshtein_aux(str1, str2, m - 1,
                          n - 1) // Replace
        );
}

unsigned levenshtein(const std::string& s1, const std::string& s2)
{
    return levenshtein_aux(s1, s2, s1.length(), s2.length());
}

std::set<std::string> Dico::find_similar(const std::string& req,
                                         unsigned size) const
{
    std::set<std::string> prefix_list;
    for (auto word : dico_)
    {
        if (levenshtein(word, req) <= size)
            prefix_list.insert(word);
    }
    return prefix_list;
}
