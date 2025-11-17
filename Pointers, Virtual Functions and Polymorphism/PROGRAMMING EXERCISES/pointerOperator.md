                            ┌──────────┬──────────────────────────────┬───────────────────────────────┬──────────────────────────────┐
                            │ Operator │ Meaning                      │ Used With                     │ Example                      │
                            ├──────────┼──────────────────────────────┼───────────────────────────────┼──────────────────────────────┤
                            │   &      │ Address-of operator          │ Normal variables              │ int *p = &x;                 │
                            │          │ (gives memory address)       │                               │ // p stores address of x     │
                            ├──────────┼──────────────────────────────┼───────────────────────────────┼──────────────────────────────┤
                            │   *      │ Dereference operator         │ Pointer variables             │ cout << *p;                  │
                            │          │ (gives value from pointer)   │                               │ // prints value at pointer   │
                            ├──────────┼──────────────────────────────┼───────────────────────────────┼──────────────────────────────┤
                            │   ->     │ Arrow operator               │ Object POINTER                │ objPtr->member;              │
                            │          │ (access member using pointer)│                               │ // same as (*objPtr).member  │
                            ├──────────┼──────────────────────────────┼───────────────────────────────┼──────────────────────────────┤
                            │   .*     │ Pointer-to-member operator   │ OBJECT (not pointer)          │ obj.*ptrToMember;            │
                            │          │ using OBJECT                 │ Rare in normal coding         │ // ptrToMember = &Class::x   │
                            ├──────────┼──────────────────────────────┼───────────────────────────────┼──────────────────────────────┤
                            │  ->*     │ Pointer-to-member operator   │ OBJECT POINTER                │ objPtr->*ptrToMember;        │
                            │          │ using POINTER                │ Rare and advanced feature     │ // pointer version of .*     │
                            └──────────┴──────────────────────────────┴───────────────────────────────┴──────────────────────────────┘
