/* Policy pattern
 * Implemented by C++
 *
 * Author wanch
 * Date 2023/7/4
 * Email wzhhnet@gmail.com
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <iostream>
#include "policy.h"

using namespace dp;

struct ElementA
{
    int x;
    int y;
};

struct ElementB
{
    int m;
    int n;
};

struct ElementC
{
    int a;
    int b;
    ElementC() : a(0), b(0) {}
    ElementC(int _a, int _b) : a(_a), b(_b) {}
    ElementC(const ElementC &orig)
    {
        *this = orig;
    }
    ElementC& operator =(const ElementC &orig)
    {
        if (&orig == this)
            return *this;
	a = orig.b;
	b = orig.b;
	return *this;
    }
    struct ElementC* Clone() const
    {
        return new ElementC(*this);
    }
};

//host classes
template <class CreationPolicy>
class Creator : public CreationPolicy
{
    //TODO(wanch):
};

//template-tameplate
template <template <class /* T */> class CreationPolicy>
class ElementManager : public CreationPolicy<ElementA>
{
    //TODO(wanch):
};

//Instantiating Creator
using ElementANewCreator = Creator<OpNewCreator<ElementA>>;
using ElementBMalloCreator = Creator<MallocCreator<ElementB>>;
using ElementCPrototypeCreator = Creator<PrototypeCreator<ElementC>>;

int main (int argc, char **argv)
{
  ElementA* a;
  ElementB* b;
  ElementC* c;

  a = ElementManager<OpNewCreator>().Create();
  std::cout << "a=" << a << std::endl;
  a = ElementManager<MallocCreator>().Create();
  std::cout << "a=" << a << std::endl;
  a = ElementManager<PrototypeCreator>().GetPrototype();
  std::cout << "a=" << a << std::endl;

  a = ElementANewCreator().Create();
  std::cout << "a=" << a << std::endl;
  b =ElementBMalloCreator().Create();
  std::cout << "b=" << b << std::endl;
  c = Creator<PrototypeCreator<ElementC>>().Create();
  std::cout << "c=" << c << std::endl;

  ElementC cc(1, 2);
  ElementCPrototypeCreator ccontr;
  ccontr.SetPrototype(&cc);
  c = ccontr.GetPrototype();
  std::cout << "c=" << c << std::endl;
  return 0;
}
