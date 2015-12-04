/*
 *   File name:	QDirStatApp.h
 *   Summary:	The QDirStat application - menu bar, tool bar, ...
 *   License:   GPL V2 - See file LICENSE for details.
 *
 *   Author:	Stefan Hundhammer <Stefan.Hundhammer@gmx.de>
 */


#ifndef QDirStatApp_h
#define QDirStatApp_h


#ifdef HAVE_CONFIG_H
#   include <config.h>
#endif

#include <kapp.h>
#include <kmainwindow.h>
#include "DirTree.h"


// Forward declarations
class QPopupMenu;
class QSplitter;

class KAction;
class KActivityTracker;
class KFeedbackDialog;
class KFeedbackDialog;
class KFeedbackQuestion;
class KPacMan;
class KPacMan;
class KRecentFilesAction;
class KToggleAction;

namespace QDirStat
{
    class CleanupCollection;
    class DirTreeView;
    class DirTreeViewItem;
    class FileInfo;
    class SettingsDialog;
    class KTreemapView;
    class KTreemapTile;
}

using namespace QDirStat;


/**
  * The base class for QDirStat application windows. It sets up the main window
  * and reads the config file as well as providing a menubar, toolbar and
  * statusbar. An instance of QDirStatView creates your center view, which is
  * connected to the window's Doc object.  QDirStatApp reimplements the methods
  * that KMainWindow provides for main window handling and supports full
  * session management as well as using KActions.
  *
  * @see KMainWindow
  * @see KApplication
  * @see KConfig
  *
  * @author Source Framework Automatically Generated by KDevelop,
  *	    (c) The KDevelop Team.
  *
  * @version KDevelop version 1.2 code generation
  **/
class QDirStatApp : public KMainWindow
{
    Q_OBJECT

public:

    /**
     * Construtor of QDirStatApp, calls all init functions to create the
     * application.
     **/
    QDirStatApp( QWidget* parent=0, const char* name=0 );

    /**
     * Destructor.
     **/
    virtual ~QDirStatApp();

    /**
     * Open an URL specified by command line argument.
     **/
    void openURL( const KURL & url );

    /**
     * Return the main window's @ref DirTreeView.
     **/
    DirTreeView * treeView() const { return _treeView; }

    /**
     * Returns the main window's @ref KTreemapView or 0 if there is none.
     *
     * Caution: Do not try to cache this value. The treemap view is destroyed
     * and re-created frequently!
     **/
    KTreemapView * treemapView() const { return _treemapView; }


public slots:

    /**
     * Open a directory tree.
     **/
    void fileAskOpenDir();

    /**
     * Open a (possibly remote) directory tree.
     **/
    void fileAskOpenUrl();

    /**
     * Refresh the entire directory tree, i.e. re-read everything from disk.
     **/
    void refreshAll();

    /**
     * Refresh the selected subtree, i.e. re-read it from disk.
     **/
    void refreshSelected();

    /**
     * Refresh the entire directory tree, i.e. re-read everything from disk.
     **/
    void stopReading();

    /**
     * Open a directory tree from the "recent" menu.
     **/
    void fileOpenRecent( const KURL& url );

    /**
     * asks for saving if the file is modified, then closes the current file
     * and window
     **/
    void fileCloseDir();

    /**
     * put the marked text/object into the clipboard
     **/
    void editCopy();

    /**
     * Notification that the view's selection has changed.
     * Enable/disable user actions as appropriate.
     **/
    void selectionChanged( FileInfo *selection );

    /**
     * Ask user what application to open a file or directory with
     **/
    void cleanupOpenWith();

    /**
     * Toggle treemap view
     **/
    void toggleTreemapView();

    /**
     * Zoom in the treemap at the currently selected tile.
     **/
    void treemapZoomIn();

    /**
     * Zoom out the treemap after zooming in.
     **/
    void treemapZoomOut();

    /**
     * Select the parent of the currently selected treemap tile.
     **/
    void treemapSelectParent();

    /**
     * Rebuild the treemap.
     **/
    void treemapRebuild();

    /**
     * Invoke online help about treemaps.
     **/
    void treemapHelp();

    /**
     * Open settings dialog
     **/
    void preferences();

    /**
     * Changes the statusbar contents for the standard label permanently, used
     * to indicate current actions.
     *
     * @param text the text that is displayed in the statusbar
     **/
    void statusMsg( const QString &text );

    /**
     * Opens a context menu for tree view items.
     **/
    void contextMenu( DirTreeViewItem * item, const QPoint &pos );

    /**
     * Opens a context menu for treemap tiles.
     **/
    void contextMenu( KTreemapTile * tile, const QPoint &pos );

    /**
     * Create a treemap view. This makes only sense after a directory tree is
     * completely read.
     **/
    void createTreemapView();

    /**
     * Create a treemap view after all events are processed.
     **/
    void createTreemapViewDelayed();

    /**
     * Delete an existing treemap view if there is one.
     **/
    void deleteTreemapView();

    /**
     * Sends a user feedback mail.
     **/
    void sendFeedbackMail();

    /**
     * Read configuration for the main window.
     **/
    void readMainWinConfig();

    /**
     * Save the main window's configuration.
     **/
    void saveMainWinConfig();

    /**
     * Revert all cleanups to default values.
     **/
    void revertCleanupsToDefaults();

    /**
     * For the settings dialog only: Return the internal cleanup collection.
     **/
    CleanupCollection * cleanupCollection() { return _cleanupCollection; }

    /**
     * Initialize @ref KPacMan animation in the tool bar.
     **/
    void initPacMan( bool enablePacMan = true );

    /**
     * Returns true if the pacman animation in the tool bar is enabled, false
     * otherwise.
     **/
    bool pacManEnabled() const { return _pacMan != 0; }

    /**
     * Ask user if he wouldn't like to rate this program.
     **/
    void askForFeedback();

    /**
     * Notification that a feedback mail has been sent, thus don't remind
     * the user any more.
     **/
    void feedbackMailSent();

    /**
     * Update enabled/disabled state of the user actions.
     **/
    void updateActions();

    /**
     * Open a file selection box to save the current directory tree to a
     * kdirstat cache file
     **/
    void askWriteCache();

    /**
     * Open a file selection box to read a directory tree from a kdirstat cache
     * file
     **/
    void askReadCache();


signals:

    /**
     * Emitted when the configuration is to be read - other than at program
     * startup / object creation where each object is responsible for reading
     * its configuraton at an appropriate time.
     **/
    void readConfig();

    /**
     * Emitted when the configuration is to be saved.
     **/
    void saveConfig();


protected:

    /**
     * Initialize the KActions of the application.
     **/
    void initActions();

    /**
     * Initialize @ref Cleanup actions.
     **/
    void initCleanups();

    /**
     * Set up status bar for the main window by initializing a status label.
     **/
    void initStatusBar();

    /**
     * Set up the activity tracker.
     **/
    void initActivityTracker();

    /**
     * Called when a main window is to be closed.
     *
     * Returns "true" when closing this window is OK, "false" to abort closing.
     **/
    virtual bool queryClose();

    /**
     * Called when the application is to be shut down alltogether, i.e. when
     * all windows are to be closed.
     *
     * Returns "true" when exiting is OK, "false" otherwise.
     **/
    virtual bool queryExit();

    /**
     * Save the window properties for each open window during session end to
     * the session config file, including saving the currently opened file by a
     * temporary filename provided by KApplication.
     *
     * @see KTMainWindow#saveProperties
     **/
    virtual void saveProperties( KConfig * config );

    /**
     * Reads session config file and restore application state including the
     * last opened files and documents by reading the temporary files saved by
     * saveProperties().
     *
     * @see KTMainWindow#readProperties
     **/
    virtual void readProperties( KConfig * config );


    /**
     * Add a list of features of this program to a feedback question
     **/
    void addFeatureList( KFeedbackQuestion * question );

    /**
     * Check if the user should be reminded to submit feedback.
     **/
    bool doFeedbackReminder();


    //
    // Data members
    //

    // Widgets

    QSplitter *			_splitter;
    DirTreeView *		    _treeView;
    KTreemapView *		    _treemapView;
    KPacMan *			_pacMan;
    QWidget *			_pacManDelimiter;
    QPopupMenu *		_treeViewContextMenu;
    QPopupMenu *		_treemapContextMenu;
    QDirStat::SettingsDialog *	_settingsDialog;
    KFeedbackDialog *		_feedbackDialog;
    KActivityTracker *		_activityTracker;


    // Actions

    KAction * 			_fileAskOpenDir;
    KAction * 			_fileAskOpenUrl;
    KRecentFilesAction *	_fileOpenRecent;
    KAction * 			_fileCloseDir;
    KAction * 			_fileRefreshAll;
    KAction *			_fileRefreshSelected;
    KAction *			_fileReadExcludedDir;
    KAction *			_fileContinueReadingAtMountPoint;
    KAction *			_fileStopReading;
    KAction *			_fileAskWriteCache;
    KAction *			_fileAskReadCache;
    KAction * 			_fileQuit;
    KAction * 			_editCopy;
    KAction * 			_cleanupOpenWith;
    KAction *	 		_treemapZoomIn;
    KAction *			_treemapZoomOut;
    KAction *			_treemapSelectParent;
    KAction * 			_treemapRebuild;

    KAction *			_reportMailToOwner;
    KAction *			_helpSendFeedbackMail;
    KToggleAction * 		_showTreemapView;

    CleanupCollection *	_cleanupCollection;


    // Misc

    int				_treemapViewHeight;
};


#endif // QDirStatApp_h
