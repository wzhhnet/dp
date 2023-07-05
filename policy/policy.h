/* Factory pattern
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
namespace dp {

// Policy classes
template <class T>
struct OpNewCreator
{
    static T* Create()
    {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
        return new T;
    }
};

template <class T>
struct MallocCreator
{
    static T* Create()
    {
	std::cout << __PRETTY_FUNCTION__ << std::endl;
        void *buf = std::malloc(sizeof(T));
        if (!buf) return nullptr;
	return new(buf)	T;
    }
};

template <class T>
struct PrototypeCreator
{
    PrototypeCreator(T *obj = nullptr)
        : prototype_(obj) {}
    T* Create()
    {
        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return prototype_ ? prototype_->Clone() : nullptr; 
    }
    T* GetPrototype() { return prototype_; }
    void SetPrototype(T *obj) { prototype_ = obj; }

  private:
    T* prototype_;
};

}; // namespace
