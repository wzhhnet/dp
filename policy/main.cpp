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
  public: 
    ElementB* CreateElementB()
    {
        return CreationPolicy<ElementB>().Create();
    }
    ElementC* CreateElementC()
    {
        return CreationPolicy<ElementC>().Create();
    }
};

//Instantiating Creator
using ElementANewCreator = Creator<OpNewCreator<ElementA>>;
using ElementBMalloCreator = Creator<MallocCreator<ElementB>>;

int main (int argc, char **argv)
{
  ElementA* a = ElementManager<OpNewCreator>().Create();
  a = ElementManager<MallocCreator>().Create();

  ElementB* b = ElementManager<OpNewCreator>().CreateElementB();
  b = ElementManager<MallocCreator>().CreateElementB();
  ElementC* c = ElementManager<PrototypeCreator>().CreateElementC();

  ElementANewCreator().Create();
  ElementBMalloCreator().Create();
  Creator<PrototypeCreator<ElementC>>().Create();
  return 0;
}
