/* Factory pattern
 * Implemented by C++
 *
 * Author wanch
 * Date 2023/6/25
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

/// Abstract product class
class IProduct
{
  public:
    virtual ~IProduct() {}
    virtual void Polymorphism() = 0;
};

/// Abstract factory class
class IFactory
{
  public:
    virtual IProduct *Create() = 0;
    virtual std::shared_ptr<IProduct> CreateEx() = 0;
};

/// Template factory implementation
template <class T>
class FactoryImpl : public IFactory
{
  public:
    virtual IProduct *Create() override
    {
        return new T();
    }

    virtual std::shared_ptr<IProduct> CreateEx() override
    {
        return std::dynamic_pointer_cast<IProduct>(
                        std::make_shared<T>());
    }
};

}; // namespace dp
