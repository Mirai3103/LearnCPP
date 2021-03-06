#include <iostream>
#include <TextTable.h>

main()
{
    TextTable t('-', '|', '+');

    t.add("");
    t.add("Sex");
    t.add("Age");
    t.endOfRow();

    t.add("Moses");
    t.add("male");
    t.add("4556");
    t.endOfRow();

    t.add("Jesus");
    t.add("male");
    t.add("2016");
    t.endOfRow();

    t.add("Debora");
    t.add("female");
    t.add("3001");
    t.endOfRow();

    t.add("Bob");
    t.add("male");
    t.add("25");
    t.endOfRow();

    t.setAlignment(2, TextTable::Alignment::RIGHT);
    std::cout << t;
    return 0;
}