#ifndef FILECREATOR_HPP
#define FILECREATOR_HPP

#include "../base.hpp"

class filecreator
{
   private:


   public:
      filecreator() = default;

      filecreator(const filecreator&) = delete;

      ~filecreator() = default;

      void run();
};

#endif //FILECREATOR_HPP