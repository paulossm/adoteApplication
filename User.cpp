#include "headers/User.h"

#include <Wt/Auth/Dbo/AuthInfo>
#include <Wt/Dbo/Impl>

DBO_INSTANTIATE_TEMPLATES(User);

using namespace Wt;
using namespace Wt::Dbo;

User::User()
  : gamesPlayed(0),
    score(0)
{ }
