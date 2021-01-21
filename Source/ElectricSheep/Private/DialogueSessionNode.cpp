#include "DialogueSessionNode.h"
#include "DialogueSession.h"

#define LOCTEXT_NAMESPACE "DialogueSessionNode"

UDialogueSessionNode::UDialogueSessionNode()
{
#if WITH_EDITORONLY_DATA
    CompatibleGraphType = UDialogueSession::StaticClass();

    ContextMenuName = LOCTEXT("ConextMenuName", "Dialogue Session Node");
#endif
}

#if WITH_EDITOR

FText UDialogueSessionNode::GetNodeTitle() const
{
    return Paragraph.IsEmpty() ? LOCTEXT("EmptyParagraph", "(Empty paragraph)") : Paragraph;
}

void UDialogueSessionNode::SetNodeTitle(const FText& NewTitle)
{
    Paragraph = NewTitle;
}

FLinearColor UDialogueSessionNode::GetBackgroundColor() const
{
    UDialogueSession* GraphObj = Cast<UDialogueSession>(GetGraph());

    if (GraphObj == nullptr)
        return Super::GetBackgroundColor();

    switch (DialoguerPostion)
    {
    case EDialoguerPostion::Left:
        return GraphObj->LeftDialoguerBgColor;
    case EDialoguerPostion::Right:
        return GraphObj->RightDialoguerBgColor;
    default:
        return FLinearColor::Black;
    }
}

#endif

#undef LOCTEXT_NAMESPACE