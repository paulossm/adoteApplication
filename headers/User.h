#ifndef USER_H_
#define USER_H_

#include <Wt/WDateTime>
#include <Wt/Dbo/Types>
#include <Wt/Dbo/WtSqlTraits>
#include <Wt/Auth/Dbo/AuthInfo>

#include <string>

class User;
typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;
typedef Wt::Dbo::collection< Wt::Dbo::ptr<User> > Users;

class User
{
public:
  User();

  std::string name; /* a copy of auth info's user name */
  int gamesPlayed;
  long long score;
  Wt::WDateTime lastGame;
  Wt::Dbo::collection< Wt::Dbo::ptr<AuthInfo> > authInfos;

  template<class Action>
  void persist(Action& a)
  {
    Wt::Dbo::field(a, gamesPlayed, "gamesPlayed");
    Wt::Dbo::field(a, score, "score");
    Wt::Dbo::field(a, lastGame, "lastGame");

    Wt::Dbo::hasMany(a, authInfos, Wt::Dbo::ManyToOne, "user");
  }
};

DBO_EXTERN_TEMPLATES(User);

#endif // USER_H_
