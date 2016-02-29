#include "comboboxdelegate.h"
#include <QComboBox>

#include <QDebug>

ComboBoxDelegate::ComboBoxDelegate(int col, const QStringList &options, QObject *parent)
    : QStyledItemDelegate(parent)
{
    column_ = col;
    options_ = options;
}

QWidget *ComboBoxDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const
{
    // Only create combo box in the given column.
    if (index.column() != column_)
        return QStyledItemDelegate::createEditor(parent, option, index);

    QComboBox *editor = new QComboBox(parent);
    editor->setFrame(false);
    editor->addItems(options_);
    return editor;
}

void ComboBoxDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    // Only set data if in the given column.
    if (index.column() != column_)
    {
        QStyledItemDelegate::setEditorData(editor, index);
        return;
    }

    QString value = index.model()->data(index, Qt::EditRole).toString();
    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    comboBox->setCurrentIndex(comboBox->findText(value));
}

void ComboBoxDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    // Only set data if in the given column.
    if (index.column() != column_)
    {
        QStyledItemDelegate::setModelData(editor, model, index);
        return;
    }

    QComboBox *comboBox = static_cast<QComboBox*>(editor);
    QString value = comboBox->currentText();
    model->setData(index, value, Qt::EditRole);
}

void ComboBoxDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const
{
    // Only update geometry if in the given column.
    if (index.column() != column_)
    {
        QStyledItemDelegate::updateEditorGeometry(editor, option, index);
        return;
    }

    editor->setGeometry(option.rect);
}
