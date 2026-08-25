*** UID:0001WK | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:-1 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# by-type/by-template Coverage Report

## Summary

- Last generated: 2026-05-26
- Folder: `by-type/by-template`
- Coverage summary: 5 covered reconstructable rows, 1 covered ignored row, 1 uncovered inventory placeholder row.
- Confidence summary: baseline report generated from existing documentation pages and `-ignored.md`; ignored rows are driven by the local ignored ledger, while reconstructable row confidence is heuristic until IDA/MCP or manual verification raises it.
- Ordering: alphabetic by item name, except `by-memory`, which is sorted by the first address in the row.

## Covered Items To Replicate

- [UID:0001WN][AUTOBUF_unsigned_char](by-type/by-template/AUTOBUF_unsigned_char.md) : not_reconstructable : 91% : very-strong : Complete non-emitting type/template authority for `_AUTOBUF<unsigned char>`: single `LObject` base, 12-byte pointer/count layout, constructor/ordinary-destructor/resize lifecycle, exact RTTI/vtable slots and 21 references, and source emission delegated uniquely to UID00000P plus its method children under UID0000HM.
- [UID:0001WP][FolderTreePaneTreeTemplates](by-type/by-template/FolderTreePaneTreeTemplates.md) : reconstructable : 93% : very strong : Shared header-defined TreeNode/TreeStorage/Tree/TreeItor template model proven by FolderTreePane and EventDispatcher instantiations, with generic link/payload/disabled layout, exact iterator ordering and source children, declaration-generated destructor/vtable support, and canonical owner/emitter route through registered UID0004YK Tree.h.
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md) : reconstructable : 88% : strong : Header-owned FunctionObject, FunctionObject0, FunctionObjectT, PlainMemberFunctionObject0, PlainMemberFunctionObject, PlainMemberFunctionObjectT, DoubleParamMemberFunctionObject0, and DoubleParamMemberFunctionObject templates routed through UID0000JO, with exact callback layouts, complete inline template bodies in FunctionObjects.h, a single FunctionObjects.cpp self-header include, and concrete TerminalPane, PopupMenu, create-user, and Nexonclub StringBase callback contexts without duplicated feature source.
- [UID:0001WR][ProtectedArrayTemplates](by-type/by-template/ProtectedArrayTemplates.md) : reconstructable : 93% : very-strong : Complete ProtectedArray<T> declaration and reusable authored bodies emit in formal H through UID0000MU; concrete image-info and NationEntry bodies remain exact retained compiler/template instantiations, every known type/stride is preserved, and no per-instantiation authored class/file is inferred.
- [UID:0004ZL][SingletonTemplate](by-type/by-template/SingletonTemplate.md) : reconstructable : 92% : very-strong : Reusable complete `template <class T> class Singleton` declaration owned by [UID:0004ZK][Singleton](by-file/Singleton.md), with exact include-only CPP self-include, guarded H declaration, protected constructor/destructor declarations, no fields/virtuals/static cell, exact empty-base optimization and class-specific specialization/source-lifetime model, and no generic body or storage.
- [UID:0001WS][StringBaseTemplate](by-type/by-template/StringBaseTemplate.md) : reconstructable : 88% : very strong : Pointer-backed mystr::StringBase<CharT, Traits> declaration emitted through NexusTK/util/StringBase.h with exact one-pointer layout, accepted method children, explicit data(), DetachAnsiIfShared(), and ToLower() const declarations, and the header-visible inline ANSI ToLower specialization required by SoundManager out-of-line instantiation and VirusChecker inline use; exact .h-versus-included-.inl organization and broader original API spelling remain the score caps.

## Covered Items To Ignore

- [UID:0001WO][CandidateStringDequeTemplate](by-type/by-template/CandidateStringDequeTemplate.md) : ignored : 85% : very strong : Standard-library `std::deque<std::wstring>` helper materialization used by IME/InputMan; A002 2026-06-14 live IDA refresh reconfirmed helper starts/sizes, append and reserve xrefs, append/move decompilation, by-class `CandidateStringQueue` support, ignored-ledger alignment, and replacement source semantics as ordinary container use rather than a NexusTK-owned template body.

## Uncovered Items

- by-type/by-template inventory baseline : uncovered : 0% : open : Full authoritative inventory for by-type/by-template is not yet proven complete; compare this report against Wave3 when OPERATIONAL, simroot_v2, and IDA/MCP evidence.
