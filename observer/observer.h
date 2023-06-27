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
#include <list>

namespace dp {

class IObject
{
  public:
    virtual ~IObject() {};
};

class IObserver
{
  public:
    virtual void OnUpdate(IObject *obj) = 0;
};

class ISubject
{
  public:
    virtual ~ISubject() {};
    void Attach(IObserver *observer)
    {
	if (observer)
            observers_.push_back(observer);
    };
    void DeAttach(IObserver *observer)
    {
	observers_.remove(observer);
    };
    void Update(IObject *obj)
    {
        for (auto obs : observers_) {
	    obs->OnUpdate(obj);
	}
    };
  private:
    std::list<IObserver*> observers_;
};
}; // namespace dp
