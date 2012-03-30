#ifndef VK_ROSTER_H
#define VK_ROSTER_H

#include "vk_global.h"
#include <QVariant>
#include <QStringList>

namespace vk {

class Contact;
class Client;
class Buddy;
class Group;

typedef QList<Contact*> ContactList;
typedef QList<Buddy*> BuddyList;
typedef QList<Group*> GroupList;

class RosterPrivate;
class VK_SHARED_EXPORT Roster : public QObject
{
    Q_OBJECT
    Q_DECLARE_PRIVATE(Roster) 
public:
    Roster(Client *client);
    virtual ~Roster();
    Contact *contact(int id);
    Contact *contact(int id) const;
    Contact *contact(const QVariantMap &data);
    ContactList contacts() const;

    QStringList tags() const;
    void setTags(const QStringList &list);
public slots:
    void sync(const QStringList &fields = QStringList()
            << QLatin1String("first_name")
            << QLatin1String("last_name")
            << QLatin1String("online")
            << QLatin1String("photo")
            << QLatin1String("photo_big")
            << QLatin1String("photo_big_rec")
            << QLatin1String("lists")
            << QLatin1String("activity")
            );
signals:
    void contactAdded(vk::Contact *contact);
    void contactRemoved(vk::Contact *contact);
    void tagsChanged(const QStringList &);
    void syncFinished(bool success);
protected:
    QScopedPointer<RosterPrivate> d_ptr;

    //friend class Contact;
    //friend class Buddy;
    //friend class Group;

	Q_PRIVATE_SLOT(d_func(), void _q_tags_received(const QVariant &response))
	Q_PRIVATE_SLOT(d_func(), void _q_friends_received(const QVariant &response))
};

} // namespace vk

#endif // VK_ROSTER_H
