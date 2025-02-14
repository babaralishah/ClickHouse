#pragma once

#include <Parsers/IAST.h>
#include <Parsers/ASTQueryWithOnCluster.h>


namespace DB
{

class ASTCreateFunctionQuery : public IAST, public ASTQueryWithOnCluster
{
public:
    String function_name;
    ASTPtr function_core;

    bool or_replace = false;
    bool if_not_exists = false;

    String getID(char) const override { return "CreateFunctionQuery"; }

    ASTPtr clone() const override;

    void formatImpl(const FormatSettings & s, FormatState & state, FormatStateStacked frame) const override;

    ASTPtr getRewrittenASTWithoutOnCluster(const std::string &) const override { return removeOnCluster<ASTCreateFunctionQuery>(clone()); }
};

}
