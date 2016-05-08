(function(){

    var resultObject;

    function invokeEcho() {

        var echoString = $("#request")[0].value;

        var request = {
            "echoString": {
                "text": echoString
            }
        };

        var requestInfo = {
            type: "POST",
            contentType: "application/json; charset=utf-8",
            url: "/axis2/services/echo/echoString",
            async: true,
            processData: false,
            dataType: "json",
            data: JSON.stringify(request)
        };


        function onSuccess(result) {
            resultObject.text(result.echoString.text);
            resultObject.css("color", "");
        }

        function onError(none, error) {
            resultObject.text("ERROR: " + error);
            resultObject.css("color", "red");
        }

        jQuery.ajax(requestInfo)
        .success(onSuccess)
        .error(onError);
    }

    $(document).ready(function() {
        $('#invoke').bind("click", invokeEcho);
        resultObject = $('#result');
    });

})();
