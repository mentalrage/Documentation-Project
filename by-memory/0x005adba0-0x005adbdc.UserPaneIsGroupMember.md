*** UID:0004SM | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
bool UserPane::IsGroupMember(unsigned int memberId) const
{
    for (int i = 0; i < m_groupMemberCount; ++i)
    {
        if (m_groupMembers[i].memberId == memberId)
            return true;
    }

    return false;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

*** Item Summary: Exact private const UserPane membership query over signed m_groupMemberCount and the fixed 0x12c GroupMemberRecord table; linearly compares each record memberId and returns true on the first match or false after exhaustion, with two live UID0003TQ calls and no count clamp, null check, bounds repair, allocation, or compiler-support body. | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** Nested:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# 0x005adba0-0x005adbdc UserPane IsGroupMember

## Status

- Disposition: reconstructable source-authored private const UserPane method.
- Exact source signature: `bool UserPane::IsGroupMember(unsigned int memberId) const`.
- Direct owner/emitter: [UID:0000FQ][UserPane](by-class/UserPane.md); file route [UID:0000P1][UserPane](by-file/UserPane.md).
- Source placement: `NexusTK/ui/panels/UserPane.cpp`.
- The exact child owns only the membership predicate. Group-list packet parsing, marker refresh, record layout declaration, FindGroupMemberById, and caller policy remain separate source items.

## Address Range And Binary Identity

- Exact range: `[0x005adba0,0x005adbdc)`, 60 bytes.
- Executable SHA256: `E76201127A5720224741ED4B0106687265D009B6AB6E124CC63B4D5892223C6A`.
- Six basic blocks, cyclomatic complexity 3.
- Both live call sites are in UID0003TQ; there is no second caller family or pointer-table route.
- Predecessor padding: `[0x005adb97,0x005adba0)`, nine `0xCC` bytes, SHA256 `57C1D0AAEF1222FC7F655F011049271D3A843395335212156E61D3850BEB51CE`.
- Successor padding: `[0x005adbdc,0x005adbe0)`, four `0xCC` bytes, SHA256 `8843B54D2DF63CA265CF4A05D27DD2B29A74FB476D296DD44A0E171D74B441CA`.
- The successor method is [UID:0004R9][0x005adbe0-0x005adc15.UserPaneFindGroupMemberById](by-memory/0x005adbe0-0x005adc15.UserPaneFindGroupMemberById.md); the exact padding keeps the two source methods separate.

## ABI And Exact Behavior

- `ECX` carries `const UserPane *this`; the one explicit stack argument is an unsigned 32-bit member id.
- The loop index and comparison bound use the existing signed `m_groupMemberCount` field.
- Each iteration advances by exact `sizeof(GroupMemberRecord) == 0x12c` and compares the record's first dword `memberId`.
- The method returns boolean true immediately on equality and false after all records described by the signed count have been examined.
- Receiver state is read-only; `const` is source-correct and no mutable cache or marker update is present.

## Target Liveness And Policy Separation

- UID0003TQ calls this method twice in its exact short-circuit HitBar eligibility expression.
- The duplicated calls are preserved. The target does not cache the predicate result, and this method does not absorb local-player or `m_groupBarEnabled` policy.
- This child supplies only membership truth; UID0003TQ owns the policy that combines local object id, group membership, and Config group-bar state.
- The live calls eliminate the older retained-helper/no-route uncertainty.

## Layout And Type Evidence

- The complete UserPane declaration contains `GroupMemberRecord m_groupMembers[50]` followed by signed `m_groupMemberCount`.
- `GroupMemberRecord` is exactly `0x12c`; `memberId` is the first unsigned dword and the remaining record carries name/appearance/HP/MP state.
- Signed count semantics are preserved exactly. A negative count causes zero iterations through the ordinary `i < m_groupMemberCount` test; no unsigned reinterpretation or clamp is introduced.
- The method requires no pointer chasing because records are embedded in the fixed UserPane array.

## Ownership And Source Placement

- Receiver fields, record layout, sibling FindGroupMemberById, group-list parsing, marker refresh helpers, and both target calls all converge on UserPane ownership.
- MapPane is the caller and Config participates in caller policy only; neither owns the predicate.
- The method belongs in UserPane.cpp immediately before the separately documented FindGroupMemberById region in address/source-family order.

## Negative Evidence And Rejected Alternatives

- This is not `FindGroupMemberById`: it returns bool and does not expose a record pointer. The successor remains the pointer-returning lookup.
- It is not a free helper, Config method, MapPane method, STL search, compiler thunk, inline-only fragment, or retained raw duplicate.
- `memberId` is unsigned, not signed object id or record index. The binary performs equality only, but the surrounding object-id contracts and record field establish unsigned source type.
- No null receiver/array check, no count clamp to 50, no corruption repair, no early zero-id rejection, and no allocation behavior exists.
- No explicit offsets/strides, decompiler labels, raw byte-array indexing, or reverse-engineering comments appear in formal C++.

## Historical Assumptions Corrected

- Broad UserPane documentation previously retained this body as an unresolved helper beside FindGroupMemberById.
- Exact range, signed count, fixed record stride, bool return, duplicate target calls, ownership, and source name are now resolved and emitted.
- Completion/confidence `92/94` reflects exact behavior and bounded private-name uncertainty without inflating unrelated group packet/marker code.
