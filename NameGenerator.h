#include <iostream>
#include <vector>
#include <time.h>
#include "Random/Random.h"

namespace codesmith
{
    const std::string syllables[] = {
        "lee", "ni", "el", "ram", "rond"
        "le", "go", "las", "gui", "ne", "ve", "re"
        "ar", "nold", "ara", "gorn", "con",
        "lou", "hi", "ha", "ho", "zap", "the", "ma", "gick",
        "jas", "min", "on", "bal", "ta", "zar",
        "men", "thol", "su", "vi", "er", "no",
        "spar", "hawk", "ke", "mi", "ber", "he",
        "dos", "sal", "adir", "na", "tash", "ha",
        "inka", "cae", "sar", "sha", "tho",
        "bel", "gar", "ion", "ath", "pol", "gara",
        "sau", "ron", "gand", "alf", "bil", "bo",
        "a", "am", "ain", "aro", "anx", "ax", "ayx",
        "boo", "blah", "benz", "in", "gaz", "olr", "ne",
        "cha", "too", "min", "olth", "rez", "read", "me", "elp",
        "ix", "moron", "utns", "alm", "elm", "ilm", "dona", "dina",
        "six", "in", "nid", "nim", "hop", "melz", "janz", "as",
        "yrn", "asm", "min", "tho", "mas", "moon", "lite", "ern", "otu",
        "omain", "en", "sal", "adir", "leg", "end", "dom", "ains",
        "cux", "bet", "ter", "ton", "not", "to", "tak", "mut",
        "de", "dip", "wat", "rand", "xo", "mel", "pid",
        "eiz", "ex", "epat", "ena", "ble", "fuc", "byt", "me",
        "ux", "ex", "pox", "xep", "soc", "ra", "tes", "uni", "hop"
    };

    class Names
    {
    public:
        Names(int seed=0) {
            // assign default name parts
            m_syllables.assign(std::begin(syllables), std::end(syllables));
            if(seed!=0) {
                m_RandomGen.seed(seed);
            } else {
                m_RandomGen.seed(time(0));
            }
        }
        virtual ~Names() {};

    public: // public API

        const std::string& firstName(int aMaxParts=4) {
            // the first name has always atleast one syllable
            auto  c=m_RandomGen.randomInt(1, aMaxParts+1);
            m_prevFirstName.clear();
            m_prevFirstName = makeNameString(c);
            return m_prevFirstName;
        } 

        const std::string& lastName(int aMaxParts=4) {
            // Sometimes causes last name not to be generated
            auto  c=m_RandomGen.randomInt(0, aMaxParts);
            m_prevLastName.clear();
            m_prevLastName = makeNameString(c);
            return m_prevLastName;
        } 

        void setSyllables(std::vector<std::string>& aSyllables) {
            m_syllables = aSyllables;
        }

    private: // methods
        std::string makeNameString(int maxParts) {
            std::string nameStr;
            for(auto i=0; i<maxParts; ++i) {
                auto part=m_RandomGen.randomInt(0, m_syllables.size());
                nameStr.append(m_syllables.at(part));
            }
            return nameStr;
        }

    private:// Data
        std::vector<std::string> m_syllables;
        std::string m_prevFirstName;
        std::string m_prevLastName;
        Random m_RandomGen;
    };
}
