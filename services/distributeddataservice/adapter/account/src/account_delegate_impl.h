/*
 * Copyright (c) 2021 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef DISTRIBUTEDDATAMGR_ACCOUNT_DELEGATE_IMPL_H
#define DISTRIBUTEDDATAMGR_ACCOUNT_DELEGATE_IMPL_H

#include "account_delegate.h"
#include <mutex>
#include <memory.h>
#include "concurrent_map.h"
#include "ohos/aafwk/content/intent.h"
#include "log_print.h"

namespace OHOS {
namespace DistributedKv {
class AccountDelegateImpl final : public AccountDelegate {
public:
    static AccountDelegateImpl *GetInstance();
    static AccountDelegate *GetBaseInstance();
    Status Subscribe(std::shared_ptr<Observer> observer) override;
    Status Unsubscribe(std::shared_ptr<Observer> observer) override;
    std::string GetCurrentHarmonyAccountId(const std::string &bundleName = "") const override;
    std::string GetDeviceAccountIdByUID(int32_t uid) const override;
    void SubscribeAccountEvent() override;
private:
    ~AccountDelegateImpl();
    void NotifyAccountChanged(const AccountEventInfo &accountEventInfo);

    ConcurrentMap<std::string, std::shared_ptr<Observer>> observerMap_ {};
};
}  // namespace DistributedKv
}  // namespace OHOS
#endif // DISTRIBUTEDDATAMGR_ACCOUNT_DELEGATE_IMPL_H
