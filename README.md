Simple scifi/fantasy name generator done with C++

Date: December 11th 2021
Author: Erno Pakarinen (codesmith)
Mail-to: codesmith.fi@gmail.com

Description:
This is a simple name generator that can be used in games to automatically generate random names. Generator is header only implementation.

Name generation is based on predefined word parts (syllables) which are used by the generator.

First name always has atleast one part.
Last name can be either zero or more parts so certain names only have a first name.

By default it uses a small predefined list of name parts but you can submit your own list of parts using the method ```setSyllables```.

Note this is just an example and the default name parts come from my mind, not from any official fantasy/scifi name list. So it will generate very odd names. But feel free to modify it for your own purposes.

Sample usage can be found in main.cpp.


Please contact me for any questions.
MIT License, feel free to fork, use, modify and extent.
