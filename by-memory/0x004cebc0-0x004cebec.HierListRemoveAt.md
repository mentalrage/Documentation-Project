*** UID:0002II | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:75 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_UID: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** AUTOGEN_PARENT_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***

# 0x004cebc0-0x004cebec HierListRemoveAt

## Status

- Entity kind: class virtual method
- Owner: [UID:000065][HierList](by-class/HierList.md)
- Likely source file: [UID:0000JV][HierList](by-file/HierList.md)
- Parent aggregate: [UID:00016X][0x004ce730-0x004cee52.HierList](by-memory/0x004ce730-0x004cee52.HierList.md)
- Rebuild handling: source-authored, reconstructable.

## Behavior

Overrides base removal to preserve hierarchy links. It delegates to the base remove-at routine and then calls [UID:0002IL][0x004ced10-0x004ceda4.HierListUpdateHierarchy](by-memory/0x004ced10-0x004ceda4.HierListUpdateHierarchy.md) for the remaining range when the removed index is not past the new tail.

## Evidence

- IDA MCP `py_eval` confirmed an IDA function object at `0x004cebc0-0x004cebec`, size `0x2c`.
- IDA xrefs show this method in the `HierList` vtable at `0x0061b360`.
- IDA xrefs to `0x004ced10` include the update call from `0x004cebe1`.

## Confidence And Caveats

The method role is strong. Final source code is deferred until the base `List` virtual signatures are fully reconciled.
