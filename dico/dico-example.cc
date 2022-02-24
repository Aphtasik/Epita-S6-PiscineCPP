#include <iostream>
#include <vector>

#include "dico.hh"

void print_set(std::set<std::string>&& se)
{
    for (const auto& st : se)
        std::cout << st << '\n';
}

int main()
{
    std::vector<std::string> vect_{ "tree",     "try",      "trie",    "forest",
                                    "conquest", "question", "relation" };

    Dico dico;
    for (const auto& s : vect_)
        dico.add_word(s);

    std::cout << "> base dico" << '\n';
    dico.dump_dico();

    std::cout << "\n> words that begin with \"tr\"" << '\n';
    print_set(dico.find_prefix("tr"));

    std::cout << "\n> words that end with \"tion\"" << '\n';
    print_set(dico.find_suffix("tion"));

    std::cout << "\n> words that contain \"est\"" << '\n';
    print_set(dico.contains("est"));

    std::string similar =
        "\n> words that are similar to \"trie\" with a distance of ";

    std::cout << similar << "\"0\"" << '\n';
    print_set(dico.find_similar("trie", 0));

    std::cout << similar << "\"1\"" << '\n';
    print_set(dico.find_similar("trie", 1));

    std::cout << similar << "\"2\"" << '\n';
    print_set(dico.find_similar("trie", 2));

    return 0;
}
