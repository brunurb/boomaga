/* BEGIN_COMMON_COPYRIGHT_HEADER
 * (c)LGPL2+
 *
 *
 * Copyright: 2012-2013 Boomaga team https://github.com/Boomaga
 * Authors:
 *   Alexander Sokoloff <sokoloff.a@gmail.com>
 *
 * This program or library is free software; you can redistribute it
 * and/or modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.

 * You should have received a copy of the GNU Lesser General
 * Public License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301 USA
 *
 * END_COMMON_COPYRIGHT_HEADER */


#ifndef INPUTFILE_H
#define INPUTFILE_H

#include <QString>
#include <QVector>

class ProjectPage;
class Job;

class InputFile
{
public:
    explicit InputFile(const QString &fileName, int pageCount);
    explicit InputFile(const Job &job, int pageCount);
    virtual ~InputFile();

    QString fileName() const { return mFileName; }

    QString title() const { return mTitle; }
    void setTile(const QString &value) { mTitle = value; }

    int pageCount() const { return mPages.count(); }
    QVector<ProjectPage*> pages() { return mPages; }
    QVector<ProjectPage*> pages() const { return mPages; }

    bool autoRemove() const {return mAutoRemove;}
    void setAutoRemove(bool value) { mAutoRemove = value; }

protected:
    QVector<ProjectPage*> mPages;

private:
    QString mFileName;
    QString mTitle;
    bool mAutoRemove;
};


#endif // INPUTFILE_H