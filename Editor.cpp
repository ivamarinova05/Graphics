
#include "Editor.h"

int Editor::currentSession = 0;

Editor::Editor ()
{
    currentSession++;
}

Editor::Editor(const Editor& other): sessions (other.sessions) {}

Editor& Editor::operator=(const Editor& other)
{
    if (this!= &other)
    {
        sessions.clear();
        sessions = other.sessions;
    }
    return *this;
}

Editor::~Editor() = default;

void Editor::addSession(Session& toAdd)
{
    sessions.push_back(toAdd);
}

Session& Editor::operator[](int i)
{
    return sessions[i];
}
