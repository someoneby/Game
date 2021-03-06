#include "AllItemsDB.h"
#include "vector"
#include "../../Helm/Helm.h"
#include "../../Chest/Chest.h"
#include "../../Weapon/Weapon.h"
#include "../../Reagent/Reagent.h"

AllItemsDB* AllItemsDB::m_instance = new AllItemsDB();

AllItemsDB::AllItemsDB() : m_allItemsDB { 
    new Helm(0, "", 0, 0, 0, 0, ""),
    // Helm (int id, string name, int armor, float avoidChanse, int hp, int prise, string description)
    new Helm(1, "Кастрюля дырявая", 5, 0, 10, 10, 
        "Дырявая кастрюля, которая послужила каской во время первой мировой твоему старшему брату ..\nСобсна теперь старший ты."),
    new Helm(2, "Кастрюля картавая", 7, 0, 16, 20, 
        "Если приложить её к уху, можно услышать шум моря, правда слегка картавый."),
    new Helm(3, "Ведро жестяное", 10, 0, 20, 51, 
        "Ведро из Фикспрайса сделанное из лучшего российского сырья (нет)."),
    new Helm(4, "Каска деда-электрика", 14, 0, 25, 88, 
        "Каска твего деда, которую ты с гордостью можешь носить по своему селу.\nКогда в ней смотришься в зеркало, \
        то видно 2 молнии, чтобы это могло значить, хм ..."),
    new Helm(5, "Заячьи ушки", 2, 0.3, 50, 120,
        "Начинаешь чувствовать себя как ангел Чарли. из-за чего ощущаешь себя неуязвимым ... \nОднако привлекаешь всех \
        извращенцев в округе, которые скоро тебе обьяснят что к чему."), 
    new Helm(6, "Памперс мумии", 25, 0, 40, 170,
        "Окаменевшие останки надёжно защищают твою черепушку ... \nПо крайней мере надёжнее чем кастрюля твоего брата."),
    new Helm(7, "Академическая шапочка", 30, 0.2, 70, 228,
        "Интеллект +100, сила заклинаний +300, сопротивление магии +60% ... \nЖаль что этих характеристик в игре нету, \
        п.э. из полезного только внушающий ужас вид безумного человека окончившего универ."),
    new Helm(8, "Красный кляп", 40, 0.3, 90, 300,
        "Купленный на Aliexpress, надёжно скрывает крик боли от врагов (по аналогии с коричневыми штанами)."),
    new Helm(9, "Спартанский шлем", 60, 0.2, 120, 700,
        "Нагло спижженный из музея является лучшим шлемом в игре."),


    // Chest (int id, string name, int armor, float avoidChanse, int hp, int prise, string description)
    new Chest(31, "Рваный мешок от картошки", 1, 1, 1, 1,
        "Костюм на выпускной доставшийся младшему брату от старшего."),
    new Chest(32, "Цельный мешок от картошки", 1, 1, 1, 1,
        "Костюм купленный заботливой многоденой семьёй на всю жизнь."),
    new Chest(33, "Кожаная портупея", 1, 1, 1, 1,
        "Портупея с Aliexpress надёжно защищает розовые сосцы ... \nТолько слегка натирает"),
    new Chest(34, "Бушлат", 1, 1, 1, 1,
        "Бушлат, висящий в шкафу на даче, происхождение которого не известно даже бабушке-хозяйке, \
        которая помнит как бусечка Понтий Пилат на горшок ходил."),
    new Chest(35, "Наклейки на соски", 1, 1, 1, 1,
        "Защищает от УФ-излучения в солярии, однако, благодаря эффекту placebo, неплохо защищает и в жизни."),
    new Chest(36, "латексное платье", 1, 1, 1, 1,
        "Внушает трепет в сердца любителей БДСМ и ужас остальным ... (крайне влияет на бабушек в подъезда)"),
    new Chest(37, "Бронелифчик", 1, 1, 1, 1,
        "Эффективная защита от колюще-режущих повреждений (каким образом - неизвестно)."),
    new Chest(38, "Вязаный свитер", 1, 1, 1, 1,
        "Любовь и забота, вложенные при создании бабушкой этого свитера, надёжно защитят владельца от всех бед."),


    //Weapon (int id, string name, int damage, float criticalChance, int prise, string description)
    new Weapon(61, "Test", 10, 0.1, 100, "Test"),


    //Reagent(int id, std::string name, std::string description, int prise)
    new Reagent(91, "Кожа", "Спасибо что не с жопы.", 5),
    new Reagent(92, "Кожа с жопы", "Бля...", 6) 
} {};

/*
    Return item from DB by id.
*/
IItem * AllItemsDB::getItemByID(int s_id) {
    for(auto itemPtr {m_instance->m_allItemsDB.begin()}; itemPtr != m_instance->m_allItemsDB.end(); ++itemPtr) {
        if( (*itemPtr)->getId() == s_id)
            return *itemPtr;
    }
}