/* Observer pattern
 * Implemented by C++
 *
 * Author wanch
 * Date 2023/6/27
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
#include "observer.h"

using namespace dp;

class Object : public IObject
{
  public:
    Object(bool state) : state_(state) {}
    ~Object() {}
    bool State() { return state_; }
  private:
    bool state_;
};

class ObserverA : public IObserver
{
  public:
    ObserverA() {}
    ~ObserverA() {}
    virtual void OnUpdate(IObject *obj) override
    {
	Object *deriveObj = dynamic_cast<Object*>(obj);
        std::cout << __PRETTY_FUNCTION__ << " state: " << deriveObj->State() << std::endl;
    }
};

class ObserverB : public IObserver
{
  public:
    ObserverB() {}
    ~ObserverB() {}
    virtual void OnUpdate(IObject *obj) override
    {
        Object *deriveObj = dynamic_cast<Object*>(obj);
        std::cout << __PRETTY_FUNCTION__ << " state: " << deriveObj->State() << std::endl;
    }
};

class Subject : public ISubject
{
  public:
    Subject() {}
    ~Subject() {}
    void NotifyTrue()
    {
	std::cout << __FUNCTION__ << std::endl;
        Object ot(true);
	Update(&ot);
    };
    void NotifyFalse()
    {
	std::cout << __FUNCTION__ << std::endl;
	Object of(false);
	Update(&of);
    }
};

int main(int argc, char **argv)
{
    Subject sub;
    ObserverA obsA;
    ObserverB obsB;
    sub.Attach(&obsA);
    sub.Attach(&obsB);
    sub.NotifyTrue();
    sub.NotifyFalse();
    return 0;
}

