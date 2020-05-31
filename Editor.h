#ifndef EDITOR_H
#define EDITOR_H

#include <string>
#include <vector>

#include "Session.h"

class Editor
{
    private:
    std::vector<Session> sessions;

    public:
    static int currentSession;

    Editor();
    Editor(const Editor&);
    Editor& operator= (const Editor&);
    ~Editor();

    void addSession (Session&);
    Session& operator[] (int);
    int sessionsNumber () {return sessions.size();}
    



};

#endif
