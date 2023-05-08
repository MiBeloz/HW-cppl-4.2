#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_session.hpp>

#include "List.cpp"


TEST_CASE("test List functions", "[List]") {
    setlocale(LC_ALL, "ru");
        
    List test_list;

    SECTION("Проверка методов PopFront() и PopBack() на пустом списке") {
        INFO("Проверка метода PopFront() на пустом списке");
        try {
            test_list.PopFront();
        }
        catch (std::runtime_error ex) {
            CHECK_THROWS(throw std::runtime_error(ex.what()));
            CHECK(test_list.Empty());
            CHECK(test_list.Size() == 0);
        }

        INFO("Проверка метода PopBack() на пустом списке");
        try {
            test_list.PopBack();
        }
        catch (std::runtime_error ex) {
            CHECK_THROWS(throw std::runtime_error(ex.what()));
            CHECK(test_list.Empty());
            CHECK(test_list.Size() == 0);
        }
    }
		
    SECTION("Проверка методов PushBack() и PushFront()") {
        INFO("Проверка метода PushBack()");
        test_list.PushBack(3);
        test_list.PushBack(5);
        CHECK_FALSE(test_list.Empty());
        CHECK(test_list.Size() == 2);

        INFO("Проверка метода PushFront()");
        test_list.PushFront(7);
        CHECK_FALSE(test_list.Empty());
        CHECK(test_list.Size() == 3);
    }
    
    SECTION("Проверка методов PopFront() и PopBack() на не пустом списке") {
        test_list.PushBack(3);
        test_list.PushBack(5);
        test_list.PushFront(7);

        INFO("Проверка метода PopBack()");
        try {
            CHECK(test_list.PopBack() == 5);
        }
        catch (std::runtime_error ex) {
            CHECK_NOTHROW(throw std::runtime_error(ex.what()));
            CHECK(test_list.Size() == 2);
            CHECK_FALSE(test_list.Empty());
        }

        INFO("Проверка метода PopFront()");
        try {
            CHECK(test_list.PopFront() == 7);
        }
        catch (std::runtime_error ex) {
            CHECK_NOTHROW(throw std::runtime_error(ex.what()));
            CHECK(test_list.Size() == 1);
            CHECK_FALSE(test_list.Empty());
        }
    }
}

int main(int argc, char* argv[]) {
    return Catch::Session().run(argc, argv);
}
