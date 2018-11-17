#include "widgets/resourcestree.h"
#include "widgets/decorationdelegate.h"
#include "apk/resourcemodelindex.h"

ResourcesTree::ResourcesTree(QWidget *parent) : QTreeView(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    setSelectionBehavior(QAbstractItemView::SelectRows);
    setItemDelegate(new DecorationDelegate(QSize(16, 16), this));
}

ResourcesModel *ResourcesTree::model()
{
    return static_cast<ResourcesModel *>(QTreeView::model());
}

void ResourcesTree::setModel(ResourcesModel *model)
{
    QTreeView::setModel(model);
    sortByColumn(0, Qt::DescendingOrder);
    setColumnWidth(ResourcesModel::NodeCaption, 120);
    setColumnWidth(ResourcesModel::ResourceLocale, 64);
    setColumnWidth(ResourcesModel::ResourcePath, 500);
}
